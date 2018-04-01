FROM ubuntu:latest
ADD . /code
WORKDIR /code
RUN echo "APT::Get::Assume-Yes "true";" >> /etc/apt/apt.conf.d/forceyes && \
    echo "APT::Get::force-yes "true";" >> /etc/apt/apt.conf.d/forceyes && \
    apt-get  update && apt-get  upgrade && \
    apt-get  install golang ca-certificates git sudo && \
    export GOPATH=/code/go && \
    export PATH=$PATH:$GOROOT/bin:$GOPATH/bin && \
    go get -u -d gocv.io/x/gocv 
WORKDIR /code/go/src/gocv.io/x/gocv
RUN make deps_debian
RUN make download 
RUN make build
RUN make cleanup
#WORKDIR /code

#make /code/go/src/gocv.io/x/gocv/deps

# apt-get -y install software-properties-common &&\
#     add-apt-repository ppa:gophers/archive && \
#     apt-get -y update && \
#     apt-get -y install golang-1.10-go && \
