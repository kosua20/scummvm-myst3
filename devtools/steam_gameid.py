#!/usr/bin/env python3

# This script takes the game name as parameter and returns the steam game id
# Return with exit code 127 if no game was found for the given title
# Return with exit code 1 if there are multiple games for the given name
# Return with exit code 0 if there is exactly one match found

import requests
import argparse
import urllib.parse
from requests_html import HTMLSession
import sys

parser = argparse.ArgumentParser()
parser.add_argument('-n', '--name', required=True, help="The steam game name")
parser.add_argument('-c', '--category', default='0', type=int, help="The category, e.g. achievements are 22")
parser.add_argument('-a', '--all', action='store_true', help="Show all matches, not just the exact match")
parser.add_argument('-v', '--verbose', action='store_true', help="Also print some meta information next to the steam game id")
args = parser.parse_args()

searchurl = "https://steamdb.info/search/?a=app&type=1&category={1}&q={0}".format(urllib.parse.quote_plus(args.name, safe='!'), args.category)
if args.verbose:
	sys.stderr.write('query url: {0}\n'.format(searchurl))

try:
	session = HTMLSession()
	response = session.get(searchurl)
	game_rows = response.html.xpath("//tr[@class='app']/td")
	game_columns = 4 # id, text, type, name, last changed
	entries = int(len(game_rows) / game_columns)
	if args.verbose:
		sys.stderr.write('found {0} games\n'.format(entries))

	matches = 0
	for i in range(entries):
		idx               = game_columns * i
		game_id           = game_rows[idx + 0].text.strip()
		game_type         = game_rows[idx + 1].text.strip()
		game_name         = game_rows[idx + 2].text.strip()
		game_last_changed = game_rows[idx + 3].attrs["title"].strip()
		if not args.all and game_name != args.name:
			if args.verbose:
				sys.stderr.write('found {0} - no match for {1}\n'.format(game_name, args.name))
			continue
		if args.verbose:
			print("{0} {1} {2}#{3}".format(game_id, game_type, game_last_changed, game_name))
		else:
			print("{0}".format(game_id))
		matches += 1

	if matches == 0:
		sys.exit(127)
	if matches > 1:
		sys.exit(1)
except requests.exceptions.RequestException as e:
	print(e)
