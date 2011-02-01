#!/usr/bin/python
# -*- coding:utf-8; tab-width:4; mode:python -*-

import unittest

from romannumerals import ArabianToRoman

class ArabianToRomanTest (unittest.TestCase):
    def test_translate_1 (self):
        sut = ArabianToRoman()
        self.assertEqual(1, sut.translate("1"))


if __name__ == '__main__':
    unittest.main()
