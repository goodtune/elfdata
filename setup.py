from setuptools import Extension, setup

setup(
    name="elflookup",
    version="0.1.0",
    url="https://github.com/goodtune/elfdata",
    author="Gary Reynolds",
    author_email="gary.reynolds@touchtechnology.com.au",
    ext_modules=[Extension("elflookup", ["pyelflookup.c"])],
    py_modules=["pyelfdata"],
    entry_points={"console_scripts": ["elfdata=pyelfdata:main"]},
)
