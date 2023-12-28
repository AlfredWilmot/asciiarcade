FROM gcc:12.2.0

ARG WORKDIR=$WORKDIR

ENV WORKDIR=$WORKDIR
ENV CPPUTEST_HOME=/opt/cpputest
ENV CONTAINER_WORKDIR=/home


# Install cpputest
WORKDIR /opt/cpputest

RUN git clone --depth 1 --branch v4.0 https://github.com/cpputest/cpputest.git .
RUN autoreconf . -i && \
    ./configure && \
    make tdd && \
    make install 

WORKDIR ${CONTAINER_WORKDIR}

ENTRYPOINT ["make"]

# References:
# > https://github.com/jwgrenning/cpputest-starter-project/blob/master/docker/Dockerfile
# > https://github.com/jwgrenning/cpputest-starter-project/blob/master/docker/run.sh
