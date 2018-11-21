#include "PC_FileIO.c"
#ifndef CALCULATE_STATS
#define CALCULATE_STATS
int ammoRemaining = 0;


void calculateStats(int runTime, string missionStatus, int targetsShot, int totalTargets, bool isAttacked)

{

	TFileHandle fout;

	bool fileOkay = openWritePC(fout, "stats.txt");



	runTime = time1[T1] / 1000;

	writeLongPC(fout,runTime);

	writeTextPC(fout, " seconds");

	writeEndlPC(fout);

	writeLongPC(fout, targetsShot);

	writeTextPC(fout, " geese shot");

	writeEndlPC(fout);

	if (ammoRemaining < 8)
	{
		writeTextPC(fout, "Robot needs reloading");

		writeEndlPC(fout);
	}
	else if (ammoRemaining == 8)
	{
		writeTextPC(fout, "Robot does not need reloading");

		writeEndlPC(fout);
	}


	if (isAttacked)
	{
		missionStatus = "Mission was a Failure";

		writeTextPC(fout, "Mission was a Failure");

		writeEndlPC(fout);
	}
	else if(totalTargets - targetsShot == 0)
	{
		missionStatus = "Mission was a Success!";

		writeTextPC(fout, "Mission was a Success!");

		writeEndlPC(fout);
	}
	else (totalTargets - targetsShot != 0)
	{
		missionStatus = "Mission was a Failure";

		writeTextPC(fout, "Mission was a Failure");

		writeEndlPC(fout);
	}


	closeFilePC(fout);

}

#endif