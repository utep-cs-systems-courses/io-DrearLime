all:
	(cd timerLib && make install)
	(cd project && make)

clean:
	(cd timerLib && make clean)
	(cd project && make clean)
	rm -rf h lib
