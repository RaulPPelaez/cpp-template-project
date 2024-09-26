# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information
import os

project = os.getenv("PROJECT_NAME", "default name")
author = os.getenv("AUTHOR_NAME", "unknown")
copyright = os.getenv("COPYRIGHT", "2024, Raul")

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = ["breathe"]

# Breathe Configuration
breathe_default_project = project
breathe_default_members = (
    "members",
    "undoc-members",
)  # Document class members by default
templates_path = ["_templates"]
exclude_patterns = []

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = "alabaster"
html_static_path = ["_static"]

# Adding to this variable allows to pass variables to the ReST files.
rst_epilog = """
.. |project| replace:: {}
""".format(
    project
)
