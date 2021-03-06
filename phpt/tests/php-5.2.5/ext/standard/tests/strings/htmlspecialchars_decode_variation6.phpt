--TEST--
Test htmlspecialchars_decode() function : usage variations - binary safe
--FILE--
<?php
/* Prototype  : string htmlspecialchars_decode(string $string [, int $quote_style])
 * Description: Convert special HTML entities back to characters
 * Source code: ext/standard/html.c
*/

/*
 * testing whether htmlspecialchars_decode() is binary safe or not
*/

echo "*** Testing htmlspecialchars_decode() : usage variations ***\n";

//various string inputs
$strings = array (
  "\tHello \$world ".chr(0)."\&!)The big brown fox jumped over the\t\f lazy dog\v\n",
  "\tHello \"world\"\t\v \0 This is a valid\t string",
  b"This is a binary\t \v\fstring",
  "This converts\t decimal to \$string".decbin(65)."Hello world"
);

//loop through the strings array to check if htmlspecialchars_decode() is binary safe
$iterator = 1;
foreach($strings as $value) {
      echo "-- Iteration $iterator --\n";
      var_dump( htmlspecialchars_decode($value) );
      $iterator++;
}

echo "Done";
?>
--EXPECTF--
*** Testing htmlspecialchars_decode() : usage variations ***
-- Iteration 1 --
string(65) "	Hello $world  \&!)The big brown fox jumped over the	 lazy dog
"
-- Iteration 2 --
string(42) "	Hello "world"	   This is a valid	 string"
-- Iteration 3 --
string(26) "This is a binary	 string"
-- Iteration 4 --
string(51) "This converts	 decimal to $string1000001Hello world"
Done
