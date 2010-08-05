/*
 * ConfigTest.cpp
 *
 *  Created on: Jul 30, 2010
 *      Author: james.cape
 */

#include "ntkn-seshat-test.h"
#include "decoder-test-common.h"

#include <MessageDecoder.h>
#include <deserializer/DeserializingDecoder.h>
#include <SocketException.h>
#include <InvalidGroupException.h>
#include <InvalidIfaceException.h>
#include <InvalidPortException.h>

#include <boost/lexical_cast.hpp>

#include <iostream>
#include <string>
#include <math.h>

using namespace std;
using namespace com::ntkn::seshat;



#define MESSAGE_COUNT 299

extern void init();
extern char ** messageData;
extern MessageHeader * messageHeaders;
extern std::vector<TestMessageField> fields[MESSAGE_COUNT];

#define BOOST_TEST_MODULE TestConfig



BOOST_AUTO_TEST_SUITE( test_message_decoder );

// Test Valid Input #1
BOOST_AUTO_TEST_CASE( test_decode_header )
//void a()
{
	init();
	MessageDecoder * messageDecoder = new DeserializingDecoder();

	for (int i = 0; i < MESSAGE_COUNT; i++)
	{
		IndicatorMessage * message = messageDecoder->decodeByteArray(messageData[i]);
		MessageHeader header = messageHeaders[i];

		BOOST_REQUIRE( message->getLength() == header.messageLength);
		BOOST_REQUIRE( message->getTransmitId() == header.txmitId );
		BOOST_REQUIRE( message->getTypeId() == header.typeId );
		BOOST_REQUIRE( message->getVersion() == header.version );
		BOOST_REQUIRE( message->getCategoryId() == header.categoryId );
		BOOST_REQUIRE( message->getMessageId() == header.messageId );

		std::vector<TestMessageField> & testMessageFields = fields[i];
	}
}

// Test Valid Input #1

void compareExpectedAndActualField(TestMessageField * testIter,const IndicatorMessageField * iter, int i);

BOOST_AUTO_TEST_CASE( test_decode_payload )
//void a()
{
	init();
	MessageDecoder * messageDecoder = new DeserializingDecoder();

	for (int i = 0; i < MESSAGE_COUNT; i++)
	{
		IndicatorMessage * message = messageDecoder->decodeByteArray(messageData[i]);
		MessageHeader header = messageHeaders[i];

		BOOST_REQUIRE( message->getLength() == header.messageLength);
		BOOST_REQUIRE( message->getTransmitId() == header.txmitId );
		BOOST_REQUIRE( message->getTypeId() == header.typeId );
		BOOST_REQUIRE( message->getVersion() == header.version );
		BOOST_REQUIRE( message->getCategoryId() == header.categoryId );
		BOOST_REQUIRE( message->getMessageId() == header.messageId );


		std::vector<TestMessageField> & testMessageFields = fields[i];

		const std::vector<IndicatorMessageField > & messageFields = message->getFields();

		//loop through all the message fields, and make sure that there is a corresponding
		//field from the test list of feilds. Then make sure that all the data matches
		for (std::vector<IndicatorMessageField>::const_iterator iter = messageFields.begin();
				iter != messageFields.end(); iter++)
		{
			bool found = false;
			for (std::vector<TestMessageField>::iterator testIter = testMessageFields.begin();
					testIter != testMessageFields.end(); testIter++)
			{
				if (testIter->id == iter->getFieldId())
				{
					found = true;
					compareExpectedAndActualField(&(*testIter),&(*iter),i);
				}
			}
			BOOST_CHECK_MESSAGE(found,"Datum not found in test data: "<<iter->getFieldId());
		}

		//do the same, except start with the test data, and compare that with the decoded array
		for (std::vector<TestMessageField>::iterator testIter = testMessageFields.begin();
							testIter != testMessageFields.end(); testIter++)
		{
			bool found = false;
			for (std::vector<IndicatorMessageField>::const_iterator iter = messageFields.begin();
							iter != messageFields.end(); iter++)
			{
				if (testIter->id == iter->getFieldId())
				{
					found = true;
					compareExpectedAndActualField(&(*testIter),&(*iter),i);
				}
			}
			BOOST_CHECK_MESSAGE(found,"Datum not found in decoded data: "<<testIter->id);

		}
	}
}

void compareExpectedAndActualField(TestMessageField * testIter,const IndicatorMessageField * iter, int i)
{
	BOOST_CHECK_MESSAGE( testIter->type == iter->getFieldType(),"Wrong field type, expected ["
								<< testIter->type <<"] got ["<< int(iter->getFieldType())<<"]");


	try {
		double expected = 0;
		double actual = 0;
		try
		{
		double expected = boost::lexical_cast<double>(testIter->value);
		double actual =   boost::lexical_cast<double>(iter->getValueAsString());
		}catch (std::exception e) {
			BOOST_CHECK_MESSAGE(false,"Exception thrown on casting "
					<< e.what()
					<<"Expected: [" << testIter->value << "] got ["	<< iter->getValueAsString()
					<<"] type: [" << testIter->type
					<<"] index: [" << i << "] datum [" << testIter->id);
		}
		BOOST_CHECK_MESSAGE(expected == actual,
									"Expected: [" << expected << "] got ["
									<< actual <<"] type: [" << testIter->type <<"] index: [" << i << "]");
	} catch (std::exception e) {
		BOOST_CHECK_MESSAGE(false,"Exception thrown" << e.what()<<"] type: [" << testIter->type <<"] index: [" << i << "] datum [" << testIter->id);
	}
}

BOOST_AUTO_TEST_SUITE_END();

