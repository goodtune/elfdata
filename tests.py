import tempfile
import unittest

import elflookup


class DemoTest(unittest.TestCase):
    def test_PRODUCT_NAME(self):
        self.assertEqual(
            elflookup.elf_section_file("PRODUCT_NAME", "demo"), "alternate name"
        )

    def test_PRODUCT_VERSION(self):
        self.assertEqual(elflookup.elf_section_file("PRODUCT_VERSION", "demo"), "1.0.0")

    def test_file_not_found(self):
        with tempfile.NamedTemporaryFile(delete=True) as tmp:
            pass
        with self.assertRaises(FileNotFoundError):
            elflookup.elf_section_file("SECTION", tmp.name)


if __name__ == "__main__":
    unittest.main(verbosity=2)
