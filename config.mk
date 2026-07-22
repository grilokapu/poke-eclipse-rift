# Enable LTO when making a release build. Disable by setting to 0.
USE_LTO_ON_RELEASE ?= 1

# Use the modern system ARM toolchain for pokeemerald-expansion builds.
# The CFRU-compatible devkitARM r47 is intentionally exposed earlier in the
# user's global PATH, so pinning this project to /usr prevents the two
# toolchains from interfering with each other. This can still be overridden
# for a one-off build with `make DEVKITARM=/path/to/another/toolchain`.
DEVKITARM ?= /usr
