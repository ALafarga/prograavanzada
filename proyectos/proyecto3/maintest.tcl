#!/usr/bin/expect -f

# For colors

proc capability cap {expr {![catch {exec tput -S << $cap}]}}
proc colorterm {} {expr {[capability setaf] && [capability setab]}}
proc tput args {exec tput -S << $args >/dev/tty}
array set color {black 0 red 1 green 2 yellow 3 blue 4 magenta 5 cyan 6 white 7}
proc foreground x {exec tput -S << "setaf $::color($x)" > /dev/tty}
proc background x {exec tput -S << "setab $::color($x)" > /dev/tty}
proc reset {} {exec tput sgr0 > /dev/tty}

#Test the program

eval spawn [lrange $argv 0 end]

#Put your test case here

#Mujer 1
expect "Intoduzca la cantidad de parejas" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "4\r"
expect "intoduzca las preferencias de la mujer 1.1" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "4\r"
expect "intoduzca las preferencias de la mujer 1.2" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "3\r"
expect "intoduzca las preferencias de la mujer 1.3" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "1\r"
expect "intoduzca las preferencias de la mujer 1.4" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "2\r"

#Mujer 2
expect "intoduzca las preferencias de la mujer 2.1" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "2\r"
expect "intoduzca las preferencias de la mujer 2.2" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "1\r"
expect "intoduzca las preferencias de la mujer 2.3" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "3\r"
expect "intoduzca las preferencias de la mujer 2.4" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "4\r"

#Mujer 3
expect "intoduzca las preferencias de la mujer 3.1" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "1\r"
expect "intoduzca las preferencias de la mujer 3.2" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "3\r"
expect "intoduzca las preferencias de la mujer 3.3" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "4\r"
expect "intoduzca las preferencias de la mujer 3.4" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "2\r"

#Mujer 4
expect "intoduzca las preferencias de la mujer 4.1" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "4\r"
expect "intoduzca las preferencias de la mujer 4.2" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "3\r"
expect "intoduzca las preferencias de la mujer 4.3" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "1\r"
expect "intoduzca las preferencias de la mujer 4.4" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "2\r"


#hombre 1
expect "intoduzca las preferencias del hombre 1.1" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "3\r"
expect "intoduzca las preferencias del hombre 1.2" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "2\r"
expect "intoduzca las preferencias del hombre 1.3" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "4\r"
expect "intoduzca las preferencias del hombre 1.4" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "1\r"

#hombre 2
expect "intoduzca las preferencias del hombre 2.1" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "2\r"
expect "intoduzca las preferencias del hombre 2.2" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "3\r"
expect "intoduzca las preferencias del hombre 2.3" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "1\r"
expect "intoduzca las preferencias del hombre 2.4" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "4\r"

#hombre 3
expect "intoduzca las preferencias del hombre 3.1" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "3\r"
expect "intoduzca las preferencias del hombre 3.2" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "1\r"
expect "intoduzca las preferencias del hombre 3.3" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "2\r"
expect "intoduzca las preferencias del hombre 3.4" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "4\r"

#hombre 4
expect "intoduzca las preferencias del hombre 4.1" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "3\r"
expect "intoduzca las preferencias del hombre 4.2" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "2\r"
expect "intoduzca las preferencias del hombre 4.3" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "4\r"
expect "intoduzca las preferencias del hombre 4.4" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "1\r"