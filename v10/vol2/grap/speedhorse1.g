.G1
label left "Winning Time" "(seconds)" left .3
label bot "Kentucky Derby, 1909 to 1988"
bestsofar = 1000  # Greater than first time
year = 09
copy "speedhorse.d" thru {
	bullet at year, $1
	bestsofar = min(bestsofar, $1)
	line from year, bestsofar to year+1, bestsofar
	year = year+1
}
.G2
