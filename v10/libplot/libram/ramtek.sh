trap 'rm -f /tmp/a$$ /tmp/b$$; trap 0; exit' 0 1 2 3 15
flags=
files=
for i
do
	case $i in
	-*)
		flags="$flags $i"
		;;
	*)
		files=$i
		;;
	esac
done
echo polya >/tmp/a$$
cat /etc/whoami >/tmp/b$$
n=`cmp /tmp/a$$ /tmp/b$$`
if test -z "$n"
then /usr/lib/ramtek $*
else
	cat $files|polya /usr/lib/ramtek $flags
fi
rm -f /tmp/a$$ /tmp/b$$
