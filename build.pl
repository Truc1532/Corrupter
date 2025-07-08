#!/usr/bin/perl

use File::Path qw(make_path);

my $SRC_DIR = "src";
my $CC = "gcc";
my $FINAL_DIR = "/usr/bin";

make_path($SRC_DIR);
make_path($FINAL_DIR);

system("$CC $SRC_DIR/utils.c $SRC_DIR/main.c -o corrupter");
system("mv corrupter $FINAL_DIR/");
