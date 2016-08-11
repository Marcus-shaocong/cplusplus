#!/bin/perl
#


my @Array;

for ( 1 .. 10)
{
print $_;
}

sub testArray
{
  my @array = @_;
  
  my %IPHash = map { $_ => 1} @array;
  my @IPArray;
  push @IPArray, "10.108.49.153";
  push @IPArray, "10.108.49.154";
 
  my $containAll = 1;
  foreach $item(@IPArray)
  {
   if(! $IPHash{$item} ) 
   {
   $containAll = 0;
   break;
   }
  
  }

return $containAll;
}

push @Array, "10.108.49.153";
push @Array, "10.108.49.154";
push @Array, "10.108.49.155";
push @Array, "10.108.49.156";
push @Array, "10.108.49.157";

$DB::single = 1;
my $isIn = testArray(@Array);

print "$isIn\n";


