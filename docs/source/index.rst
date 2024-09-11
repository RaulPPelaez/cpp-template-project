MyVeryCoolProject documentation
===================================

Welcome to the landing page!

A section
----------

This is the documentation for the functions inside the namespace my_library

.. doxygennamespace:: my_library

A little bit about reST
-----------------------
		      
reStructuredText can be really fancy. I can include an equation in :math:`\LaTeX` like this:

.. math::

    \int_{-\infty}^{\infty} e^{-x^2} dx = \sqrt{\pi}

And I can include a code block like this:

.. code-block:: python

    def my_function(x):
	return x**2


Also an image from an url like this:

.. image:: https://isocpp.org/assets/images/cpp_logo.png
   :alt: C++ logo
   :align: center

   

Docs
====

.. toctree::
   :maxdepth: 2
   :caption: Contents:

   a_secondary_page
