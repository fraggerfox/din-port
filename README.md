din-port
========

FreeBSD [Ports][3] script for DIN Is Noise

You can find the DIN Is Noise [here][1]

NOTE: If you would like to compile other versions of DIN, checkout the respective tag.

Installation
------------

Copy `audio/din` folder to `/usr/ports` directory.

NOTE: If your ports directory is different from above, copy to the respective
place.

Usage
-----

Once you have copied the folder, install it as you would do for any port.

`$ cd /usr/ports/audio/din`<br>
`$ make install clean`

Credits
-------

* DIN Is Noise was written by [jag][2], who helped me a lot in making
  DIN's build to be compatible with FreeBSD.
* Thanks to `@ppaeps` for helping me come up with the port package, for patching
  up minor fixes and a machine to test the port development.
* Thanks to `@aashiks` for helping me doing build and run tests in TrueOS.

License
-------

BSD 2-clause. See LICENSE.

[1]: https://dinisnoise.org/
[2]: https://dinisnoise.org/bio/
[3]: https://www.freshports.org/audio/din
