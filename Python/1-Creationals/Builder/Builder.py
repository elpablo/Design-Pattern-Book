#!/usr/bin/env python3
import os


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
        self.filename = ''

    def source_file_path(self, path):
        if os.path.exists(path):
            self.filename = path
        return self

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

    iv.image = ib.source_file_path('/path/to/a/valid/image/file.jpg').resize(100, 100).build()


if __name__ == "__main__":
    main()
