#!/usr/bin/env python
import sys
import os

def main():
    assert len(sys.argv) > 2 
    return os.system(" ".join(sys.argv[2:])) == int(sys.argv[1])

if __name__ == '__main__':
    sys.exit(main())
