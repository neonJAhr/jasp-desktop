#ifndef ENGINE_H
#define ENGINE_H

#include "../JASP-Common/dataset.h"
#include "../JASP-Common/lib_json/json.h"
#include "../JASP-Common/ipcchannel.h"
#include "../JASP-Common/process.h"

class Engine
{
public:
	explicit Engine();
	
public:

	void run();
	void setSlaveNo(int no);
	
private:

	bool receiveMessages(int timeout = 0);
	void runAnalysis();
	void sendResults();
	int callback(const std::string &results);

	std::string provideTempFilename(const std::string &extension);

	typedef enum { empty, toInit, initing, inited, toRun, running, complete, error } Status;

	Status _status;

	int _analysisId;
	std::string _analysisName;
	std::string _analysisOptions;
	std::string _analysisResults;

	IPCChannel *_channel;

	DataSet *_dataSet;

	int _slaveNo;
};

#endif // ENGINE_H
