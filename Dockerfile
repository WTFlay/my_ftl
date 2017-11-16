FROM debian:wheezy

LABEL maintainer="Flavien SCHRIEVER <schrie_f@etna-alternance.net>"

RUN echo "deb http://ftp.debian.org/debian wheezy-backports main" >> /etc/apt/sources.list \
    && apt-get update -y \
    && apt-get -t wheezy-backports install libsdl2-2.0-0 libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev -y \
    && apt-get install -y build-essential valgrind
RUN useradd -m -s /bin/bash groot

ENV DISPLAY :0
VOLUME ["/home/groot/project"]

COPY . /groot
RUN chown -R groot:groot /groot
WORKDIR /groot

USER groot:1000
RUN make re
ENTRYPOINT ["/usr/bin/valgrind", "./my_ftl"]
