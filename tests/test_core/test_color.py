from unittest import TestCase

from Chess import color


class TestColor(TestCase):

    def test_opponent(self):
        self.assertEqual(-color.white, color.black)
        self.assertEqual(-color.black, color.white)
