# my_ftl

This is a school project where the goal was to realize a game like Faster Than Light in CLI and with SDL.

## Building

```sh
make re
```

## Running

For use the CLI interface:

```sh
./my_ftl
```

And for launch with the SDL:
```sh
./my_ftl --gui
```

## Docker

I made available a Dockerfile for build and run this program with valgrind. The SDL is not available in the container.

```sh
docker build -t my_ftl .
docker run --rm -it my_ftl
```
