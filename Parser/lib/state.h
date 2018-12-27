typedef enum { VARIABLE, ARRAY } DATA_TYPE;

typedef struct{
	union{
		var opVar
		ARR opArr
	}data;
	DATA_TYPE type;
}DATA;

typedef struct{
	DATA* dat;
	char* operat;
}OP;

struct statement{
	OP* info;
	struct statement* left;
	struct statement* right;
};

typedef struct statement STATE;


STATE* stateFactory(char* buffer,int start int end ){
	
}

