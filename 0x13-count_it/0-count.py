#!/usr/bin/python3
'''
a recursive function that queries the Reddit API
'''
import requests


def count_words(subreddit, word_list, after=None):
	'''
	count words
	'''
	sub = subreddit.lower()
	words = [w.lower() for w in word_list]
	print(words)
	params = {'limit': 100}
	url = 'https://www.reddit.com/r/{}/hot'.format(sub)

	r = requests.get(url, params=params, allow_redirects=False)
	data = r.json()
	print(data)
