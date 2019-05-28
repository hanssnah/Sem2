#ifndef GRAPH_H
#define GRAPH_H
#pragma once
#define MAX_NO_OF_SAMPLES 20

namespace sict {
	void getSamples(int samples[], int noOfSamples);
	int findMax(int samples[], int noOfSamples);
	void printBar(int val, int max);
	void printGraph(int samples[], int noOfSamples);
}

#endif