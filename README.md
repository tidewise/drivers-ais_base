# ais_base

The Automatic Information System (AIS) is an automated system that broadcasts
the position, information and destination of most commercial boats. The boats
are installed with AIS emitters and receivers, allowing for a more automated
traffic control.

This package defines AIS-related data types, as well as some utility classes
needed for AIS handling. Use the `drivers/orogen/nmea0183` and
`drivers/orogen/nmea2000` packages to actually read AIS data out of the two most
common communication standards existing on ships.

# License

LGPL version 2 or later

# Installation

The easiest way to build and install this package is to use Rock's build system.
See [this page](http://rock-robotics.org/stable/documentation/installation.html)
on how to install Rock.

However, if you feel that it's too heavy for your needs, Rock aims at having
most of its "library" packages (such as this one) to follow best practices. See
[this page](http://rock-robotics.org/stable/documentation/packages/outside_of_rock.html)
for installation instructions outside of Rock.
