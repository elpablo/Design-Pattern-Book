import Foundation

class RealImage {
    let id: Int
    
    init(id: Int) {
        self.id = id
        print("   ctor: \(id)")
    }
    
    deinit {
        print("   dtor: \(id)")
    }
    
    func draw() {
        print("   drawing the image \(id)")
    }
}

class ImageProxy {
    private var theRealImage: RealImage?
    private let id: Int
    private static var next = 1
    
    init() {
        id = ImageProxy.next
        ImageProxy.next += 1
    }
    
    deinit {
        // Swift's ARC will handle memory management automatically
        print("ImageProxy deinit: \(id)")
    }
    
    func draw() {
        if theRealImage == nil {
            theRealImage = RealImage(id: id)
        }
        theRealImage?.draw()
    }
}

// Client code
var images: [ImageProxy] = []

for _ in 0..<5 {
    images.append(ImageProxy())
}

for image in images {
    image.draw()
}

// Force deallocation to see deinit messages
images.removeAll()

/**
 ctor: 1
    drawing the image 1
    ctor: 2
    drawing the image 2
    ctor: 3
    drawing the image 3
    ctor: 4
    drawing the image 4
    ctor: 5
    drawing the image 5
 ImageProxy deinit: 5
    dtor: 5
 ImageProxy deinit: 4
    dtor: 4
 ImageProxy deinit: 3
    dtor: 3
 ImageProxy deinit: 2
    dtor: 2
 ImageProxy deinit: 1
    dtor: 1
 */
