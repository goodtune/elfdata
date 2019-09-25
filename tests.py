import elflookup
import unittest


class DemoTest(unittest.TestCase):
    def test_PRODUCT_NAME(self):
        self.assertEqual(
            elflookup.elf_section_file("PRODUCT_NAME", "demo"), "alternate name"
        )

    def test_PRODUCT_VERSION(self):
        self.assertEqual(elflookup.elf_section_file("PRODUCT_VERSION", "demo"), "1.0.0")
