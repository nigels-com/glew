#!/usr/bin/python

import re

section = re.compile('^(Name|Name Strings?|Number|Dependencies|New Procedures and Functions|New Tokens|Additions to .*|Changes to .*|Modifications to .*|Add new Section .*)\s*$')
token   = re.compile('^\s+(([A-Z0-9][A-Z0-9_x]*):?\s+((?:0x)?[0-9A-F]+)([^\?]*))?\s*$')

if __name__ == '__main__':

  from optparse import OptionParser
  import os

  parser = OptionParser('usage: %prog [options] [SOURCES...]')
  (options, args) = parser.parse_args()

  for i in args:
      lines = open(i).readlines()
      f = open(i,'w')
      current = ''
      for j in lines:
          m = section.match(j)
          if m:
              current = m.group(1).strip()
              if current in [ 'Name', 'Name String', 'Name Strings', 'Number', 'Dependencies', 'New Procedures and Functions', 'New Tokens']:
                  print >>f, j,
              continue
          if current=='New Tokens':
              if token.match(j):
                  print >>f, j,
          elif current in [ 'Name', 'Name String', 'Name Strings', 'Number', 'Dependencies', 'New Procedures and Functions']:
                  print >>f, j,

