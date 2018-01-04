din-port
========

FreeBSD [Ports][3] script for DIN Is Noise

You can find the DIN Is Noise [here][1]

NOTE: This has not yet been committed to the ports repository.

NOTE: If you would like to compile DIN version 29, checkout the tag `din-29`

Installation
------------

Copy `multimedia/din` folder to `/usr/ports` directory.

NOTE: If your ports directory is different from above, copy to the respective
place.

Usage
-----

Once you have copied the folder, install it as you would do for any port.

`$ cd /usr/ports/multimedia/din`<br>
`$ make install clean`

Credits
-------

* DIN Is Noise was written by [jag][2], who helped me a lot in making
  his code build to be compatible with FreeBSD.
* Thanks to `trouble` for helping me come up with the port package and a
  machine to test the port development.
* Thanks to `aashiks` for helping me doing build and run tests in TrueOS.

License
-------

BSD 2-clause. See LICENSE.

[1]: https://dinisnoise.org/
[2]: https://dinisnoise.org/bio/
[3]: https://www.freshports.org/multimedia/din
