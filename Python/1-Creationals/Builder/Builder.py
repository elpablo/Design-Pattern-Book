#!/usr/bin/env python3


class Image:
    """
    Data object to be produced by the builder
    """
    def __init__(self):
        self.size = (0, 0)


class ImageViewer:
    """
    Class that will use the built Image object
    """
    def __init__(self):
        self.image = None


class ImageBuilder:
    """
    Builder factory class that will build the Image object through the building steps
    """
    def __init__(self, name):
        self.name = name
        self.size = (0, 0)

    def resize(self, w, h):
        self.size = (w, h)
        return self

    def build(self):
        img = Image()
        img.size = self.size
        return img


def main():
    iv = ImageViewer()
    ib = ImageBuilder('test')

    iv.image = ib.resize(100, 100).build()


if __name__ == "__main__":
    main()
