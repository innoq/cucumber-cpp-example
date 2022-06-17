FROM ubuntu:22.04

RUN apt-get update && apt-get install -y build-essential cmake ruby-rubygems ruby-dev git libboost-dev libboost-filesystem-dev libboost-program-options-dev libboost-regex-dev libboost-thread-dev libgtest-dev libboost-test-dev ruby-bundler net-tools

COPY Gemfile /tmp
COPY install_cucumber_cpp.sh /tmp
WORKDIR /tmp
RUN bundle install
RUN /tmp/install_cucumber_cpp.sh

RUN mkdir -p /app/
WORKDIR /app
