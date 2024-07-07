#!/usr/bin/env python3


class RealImage:
    def __init__(self, idx):
        self.image_id = idx
        print("Build RealImage with ID: %d" % idx)

    def draw(self):
        print("drawing the image %d" % self.image_id)


# Design an "extra level of indirection" proxy class
class ImageProxy:
    _next_id = 0

    def __init__(self):
        self._the_real_image = None
        ImageProxy._next_id += 1
        self.idx = ImageProxy._next_id

    def draw(self):
        # When a request comes in, the real object is created "on first use"
        if self._the_real_image is None:
            self._the_real_image = RealImage(self.idx)

        self._the_real_image.draw()


def main():
    print("Init proxies...")
    images = [ImageProxy() for _ in range(0, 5)]

    print("\nDrawing images... \n")
    for image in images:
        image.draw()


if __name__ == "__main__":
    main()


"""
Output:

Init proxies...

Drawing images... 

Build RealImage with ID: 1
drawing the image 1
Build RealImage with ID: 2
drawing the image 2
Build RealImage with ID: 3
drawing the image 3
Build RealImage with ID: 4
drawing the image 4
Build RealImage with ID: 5
drawing the image 5
"""
