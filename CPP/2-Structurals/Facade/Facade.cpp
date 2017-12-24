#include <iostream>

// Component: Streamer
class MediaStreamer
{
public:
    void processData()
    {
        _state = Ready;
    }

    bool checkOnStatus()
    {
        _state++;
        return _state == Complete;
    }

private:
    enum States
    {
        Ready = 0,
        CheckMediaAvailability,
        OpenMediaChannel,
        StreamData,
        ConnectionPaused,
        ConnectionRestarted,
        StreamFlushed,
        Complete
    };
    int _state;
};

// Component: Compressor
class DataCompressor
{
public:
    void processData()
    {
        _state = Ready;
    }

    bool checkOnStatus()
    {
        _state++;
        return _state == Complete;
    }

private:
    enum States
    {
        Ready = 0,
        AssignCompressionRate,
        CompressData,
        ManageCompressionError,
        CheckCompressedData,
        Complete
    };

    int _state;
};

// Component: Encoder
class DataEncoder
{
public:
    void processData()
    {
        _state = Ready;
    }

    bool checkOnStatus()
    {
        _state++;
        return _state == Complete;
    }

private:
    enum States
    {
        Ready = 0,
        ExtractDataInformation,
        EncodeData,
        ManageEncodingErrors,
        Complete
    };

    int _state;
};

// Façade class that will hide to the
// client code all the complexity of the above components
class SerializationFacade
{
public:
    SerializationFacade()
    {
        _count = 0;
    }

    void processData()
    {
        _state = Ready;
    }

    bool checkOnStatus()
    {
        _count++;
        // Data has just been received
        if (_state == Ready)
        {
            _state++;
            // Process the data with the Encoder
            _encoder.processData();
            std::cout << "submitted to Encoder - " << _count <<
              " steps so far" << std::endl;
        }
        else if (_state == SubmitToCompressor)
        {
            // If data has been encoded, forward to Compressor
            if (_encoder.checkOnStatus())
            {
                _state++;
                _compressor.processData();
                std::cout << "submitted to Compressor - " << _count <<
                  " steps so far" << std::endl;
            }
        }
        else if (_state == SubmitToStreamer)
        {
            // If Encoding is complete, forward to MediaStreamer
            if (_encoder.checkOnStatus())
            {
                _state++;
                _dataStreamer.processData();
                std::cout << "submitted to MediaStreamer - " << _count <<
                  " steps so far" << std::endl;
            }
        }
        else if (_state == StoreOnMedia)
        {
            // If data streamer is complete, job is done
            if (_dataStreamer.checkOnStatus())
            {
                return true;
            }
        }

        // The job is not entirely complete
        return false;
    }

    int getNumberOfIterations()
    {
        return _count;
    }

private:
    enum States
    {
        Ready = 0,
        SubmitToCompressor,
        SubmitToStreamer,
        StoreOnMedia
    };

    int _state;
    int _count;

    DataCompressor _compressor;
    DataEncoder _encoder;
    MediaStreamer _dataStreamer;
};

int main()
{
    SerializationFacade serializer;
    serializer.processData();

    // Keep checking until job is complete
    while (!serializer.checkOnStatus())
    ;

    std::cout << "job completed after only "
              << serializer.getNumberOfIterations()
              << " steps" << std::endl;

    return 0;
}

//-----------------------------------------------------------
/*
Output:

submitted to Encoder - 1 steps so far
submitted to Compressor - 5 steps so far
submitted to MediaStreamer - 5 steps so far
job completed after only 12 steps

*/
