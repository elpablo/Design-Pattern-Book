#!/usr/bin/env python3

from enum import IntEnum


class StreamerStates(IntEnum):
    Ready = 0
    CheckMediaAvailability = 1
    OpenMediaChannel = 2
    StreamData = 3
    ConnectionPaused = 4
    ConnectionRestarted = 5
    StreamFlushed = 6
    Complete = 7


class MediaStreamer:
    """
    Component: Streamer
    """
    def __init__(self):
        self.state = StreamerStates.Ready

    def process_data(self):
        self.state = StreamerStates.Ready

    def check_on_status(self):
        self.state += 1
        return self.state == StreamerStates.Complete


class CompressorStates(IntEnum):
    Ready = 0
    AssignCompressionRate = 1
    CompressData = 2
    ManageCompressionError = 3
    CheckCompressedData = 4
    Complete = 5


class DataCompressor:
    """
    Component: Compressor
    """
    def __init__(self):
        self.state = CompressorStates.Ready

    def process_data(self):
        self.state = CompressorStates.Ready

    def check_on_status(self):
        self.state += 1
        return self.state == CompressorStates.Complete


class EncoderStates(IntEnum):
    Ready = 0
    ExtractDataInformation = 1
    EncodeData = 2
    ManageEncodingErrors = 3
    Complete = 4


class DataEncoder:
    """
    Component: Encoder
    """
    def __init__(self):
        self.state = EncoderStates.Ready

    def process_data(self):
        self.state = EncoderStates.Ready

    def check_on_status(self):
        self.state += 1
        return self.state == EncoderStates.Complete


class FacadeStates(IntEnum):
    Ready = 0
    SubmitToCompressor = 1
    SubmitToStreamer = 2
    StoreOnMedia = 3


class SerializationFacade:
    """
    Façade class that will hide to the client code all the complexity of the above components
    """
    def __init__(self):
        self.count = 0
        self.state = FacadeStates.Ready
        self.compressor = DataCompressor()
        self.encoder = DataEncoder()
        self.data_streamer = MediaStreamer()

    def get_number_of_iterations(self):
        return self.count

    def process_data(self):
        self.state = FacadeStates.Ready

    def check_on_status(self):
        self.count += 1

        # Data has just been received
        if self.state == FacadeStates.Ready:
            # Process the data with the Encoder
            self.state += 1
            self.encoder.process_data()
            print("submitted to Encoder - %d steps so far" % self.count)
        elif self.state == FacadeStates.SubmitToCompressor:
            # If data has been encoded, forward to Compressor
            if self.encoder.check_on_status():
                self.state += 1
                self.compressor.process_data()
                print("submitted to Compressor - %d steps so far" % self.count)
        elif self.state == FacadeStates.SubmitToStreamer:
            # If Encoding is complete, forward to MediaStreamer
            if self.compressor.check_on_status():
                self.state += 1
                self.data_streamer.process_data()
                print("submitted to MediaStreamer - %d steps so far" % self.count)
        elif self.state == FacadeStates.StoreOnMedia:
            # If data streamer is complete, job is done
            if self.data_streamer.check_on_status():
                return True

        return False


def main():
    serializer = SerializationFacade()
    serializer.process_data()

    while not serializer.check_on_status():
        pass

    print("job completed after only %d steps" % serializer.get_number_of_iterations())


if __name__ == "__main__":
    main()


"""
Output:

submitted to Encoder - 1 steps so far
submitted to Compressor - 5 steps so far
submitted to MediaStreamer - 10 steps so far
job completed after only 17 steps

"""
