//: Playground - noun: a place where people can play

import UIKit

class Image {
    func loadFrom(url: URL?) {
        
    }
    
    func resize(to size:CGSize) {
        
    }
}

class ImageViewer {
    var image: Image? = nil {
        didSet {
            print("Image assigned.")
        }
    }
}

class ImageBuilder {
    private var url: URL? = nil
    private var size: CGSize = CGSize(width: 0, height: 0)
    
    func setUrl(_ img_url: URL) -> ImageBuilder {
        self.url = img_url
        return self
    }
    
    func setSize(_ output_size: CGSize) -> ImageBuilder {
        self.size = output_size
        return self
    }
    
    func build() -> Image {
        let img: Image = Image()
        img.loadFrom(url: self.url)
        img.resize(to: self.size)
        return img
    }
}

/* Usage */

let builder: ImageBuilder = ImageBuilder()
let viewer: ImageViewer = ImageViewer()

viewer.image = builder.setUrl(URL(fileURLWithPath: "/path/to/my/image.png"))
                      .setSize(CGSize(width: 100.0, height: 100.0))
                      .build()

/**
 Output:
 
 Image assigned.
 
 */
