#include "PublishSubscribe.h"
#include <iostream> 
#include <list> 
#include <iterator> 
using namespace std;
/*
class Publisher::Publisher(void)
{

}

class Subscribe::Subscribe(void)
{
	list<>list;
public:
	PublishSubscribe();
	~PublishSubscribe();
	
};
*/
class CallbackInterface
{
public:
    // The prefix "cbi" is to prevent naming clashes.
    virtual int cbiCallbackFunction(int) = 0;
};
//The class that wants to be called back derives from the CallbackInterface and implements the callback function.
class Callee : public CallbackInterface
{
public:
    // The callback function that Caller will call.
    int cbiCallbackFunction(int i)  
    { 
        printf("  Callee::cbiCallbackFunction() inside callback\n");
        return 2 * i; 
    }

    int randomfunction(void)
    {
    	return 10;
    }
};

class Callee2 : public CallbackInterface
{
public:
    // The callback function that Caller will call.
    int cbiCallbackFunction(int i)  
    { 
        printf("  Callee2::cbiCallbackFunction() inside callback\n");
        return 2 * i; 
    }

    int randomfunction(void)
    {
    	return 10;
    }
};

class Caller 
{
public:
    // Clients can connect their callback with this
    void connectCallback(CallbackInterface *cb)
    {
        m_cb[index] = cb;
        index++;
        //callbacks.push_front(cb);
    }

    // Test the callback to make sure it works.
    void test()
    {
    	/*list <CallbackInterface *> :: iterator it;
    	for(it = callbacks.begin(); it != callbacks.end(); ++it)
    	{
    		it->cbiCallbackFunction(10);
    	}*/
    	/*list <int> :: iterator it; */
    	for (int i = 0; i < index ; ++i)
    	{
        printf("Caller::test() calling callback...\n");
        int j = m_cb[i] -> cbiCallbackFunction(10*i);

        printf("Result (20): %d\n", j);
    	}



    }

private:
	int index =0;
	//list <CallbackInterface *> :: callbacks; 
    // The callback provided by the client via connectCallback().
    CallbackInterface *m_cb[10] = {NULL};
};

int main(int argc, char const *argv[])
{
	Caller caller;
	Callee callee;
	Callee2 callee2;
	caller.connectCallback(&callee);
	caller.connectCallback(&callee2);
	caller.test();
	/* code */
	return 0;
}