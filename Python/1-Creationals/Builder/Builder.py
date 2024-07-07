#!/usr/bin/env python3
import os


class Image:
    """
    Data object to be produced by the builder
    """
    def __init__(self):
        self.size = (0, 0)
        self.filename = ""

    def load_from_path(self, path):
        self.filename = path


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
    def __init__(self):
        self.size = (0, 0)
        self.filename = ''

    def source_file_path(self, path):
        """
        It assigns the path to the file associated to the image
        :param path: the path to the image
        :return: the 'self' so to chain the call to the other steps of the builder
        """
        if os.path.exists(path):
            self.filename = path
        return self

    def resize(self, w, h):
        """
        It store the size of the image
        :param w: the width of the image
        :param h: the height of the image
        :return: the 'self' so to chain the call to the other steps of the builder
        """
        self.size = (w, h)
        return self

    def build(self):
        """
        It is the final step of the builder that will build the image and will return it to the caller
        :return: the instance of the image with the right size
        """
        img = Image()
        img.load_from_path(self.filename)
        img.size = self.size
        return img


def main():
    # Create the viewer of images
    iv = ImageViewer()

    # Create the builder that will create the image given some parameters
    ib = ImageBuilder()

    # Assign the built image to the image viewer.
    iv.image = ib.source_file_path('/path/to/a/valid/image/file.jpg').resize(100, 100).build()


if __name__ == "__main__":
    main()
