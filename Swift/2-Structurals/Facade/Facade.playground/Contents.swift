import Foundation

// Component: Streamer
class MediaStreamer {
    private enum States: Int {
        case ready, checkMediaAvailability, openMediaChannel, streamData, connectionPaused, connectionRestarted, streamFlushed, complete
    }
    private var state = States.ready
    
    func processData() {
        state = .ready
    }
    
    func checkOnStatus() -> Bool {
        state = States(rawValue: state.rawValue + 1) ?? .complete
        return state == .complete
    }
}

// Component: Compressor
class DataCompressor {
    private enum States: Int {
        case ready, assignCompressionRate, compressData, manageCompressionError, checkCompressedData, complete
    }
    private var state = States.ready
    
    func processData() {
        state = .ready
    }
    
    func checkOnStatus() -> Bool {
        state = States(rawValue: state.rawValue + 1) ?? .complete
        return state == .complete
    }
}

// Component: Encoder
class DataEncoder {
    private enum States: Int {
        case ready, extractDataInformation, encodeData, manageEncodingErrors, complete
    }
    private var state = States.ready
    
    func processData() {
        state = .ready
    }
    
    func checkOnStatus() -> Bool {
        state = States(rawValue: state.rawValue + 1) ?? .complete
        return state == .complete
    }
}

// Façade class
class SerializationFacade {
    private enum States {
        case ready, submitToCompressor, submitToStreamer, storeOnMedia
    }
    
    private var state = States.ready
    private var count = 0
    
    private let compressor = DataCompressor()
    private let encoder = DataEncoder()
    private let dataStreamer = MediaStreamer()
    
    func processData() {
        state = .ready
    }
    
    func checkOnStatus() -> Bool {
        count += 1
        
        switch state {
        case .ready:
            state = .submitToCompressor
            encoder.processData()
            print("submitted to Encoder - \(count) steps so far")
            
        case .submitToCompressor:
            if encoder.checkOnStatus() {
                state = .submitToStreamer
                compressor.processData()
                print("submitted to Compressor - \(count) steps so far")
            }
            
        case .submitToStreamer:
            if compressor.checkOnStatus() {
                state = .storeOnMedia
                dataStreamer.processData()
                print("submitted to MediaStreamer - \(count) steps so far")
            }
            
        case .storeOnMedia:
            if dataStreamer.checkOnStatus() {
                return true
            }
        }
        
        return false
    }
    
    func getNumberOfIterations() -> Int {
        return count
    }
}

// Usage
let serializer = SerializationFacade()
serializer.processData()

// Keep checking until job is complete
while !serializer.checkOnStatus() {}

print("job completed after only \(serializer.getNumberOfIterations()) steps")

/**
 submitted to Encoder - 1 steps so far
 submitted to Compressor - 5 steps so far
 submitted to MediaStreamer - 5 steps so far
 job completed after only 12 steps
 */
