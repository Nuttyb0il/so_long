# Portrait -- Sprite Engine

# Index

1. [Palette](#main-palette)
	1) [Examples](#palette-examples)
	2) [Sprite Data](#sprite-data)
2. [Compression](#compression)
	1) [Difference Storing](#difference-storing)
	2) [Pattern repeating](#pattern-repeating)
3. [Encoding and decoding](#encode-decode)
	1) [Encode](#howto-encode)
	2) [Decode](#howto-decode)

## Palette <a name="main-palette"></a>

> Sprite palette is a small index containing a maximum of 254 colors
- 1 byte for color number
- 3 byte per color *HEX (R,G,B)*

### Example <a name="palette-example"></a>
> 01 FF FF FF

*Represents a color palette of length 1, containing colors :*
1) White (0xFFFFFF)
> 02 FF FF FF 00 00 00
*Represents a color palette of length 2, containing colors :*
1) White (0xFFFFFF)
2) Black (0x000000)
> 01 FF 00 FF 00 FF 00

*Is an invalid color palette, as the fixed length is set to 1, and it contains two colors.*

**In that case the behavior is undefined**

## Sprite data <a name="sprite-data"></a>

> Sprite data is a way of storing graphics and their corresponding colors in few bytes

### Components

0) Compressed (**0x00** or **0x01**), 1 byte representing if the palette is compressed (has repeat count) or not
1) Pixel color (**0x00** to **0xFE** pixels) (correspond to a palette **index**)
***NOTE:** a palette index corresponding to 0xFF, represents rgba(0, 0, 0, 0)*
2) Blink delay (**0x01** to **0xFF**) represents a delay (in frames) where the pixel's color will be swapped to another (if the color is exactly the same, the pixel will not be drawn)
3) Repeat (**0x00** to **0xFF**) represents the number of time this color should be repeated on the same graphic line <a name="components-repeat"></a>

## Compression <a name="compression"></a>

### A list of potential algorithms that could be implemented

- Difference storing <a name="difference-storing"></a>

	> Difference storing is currently only a concept

	While creating a palette, DS algorithm can store a decimal difference (1 byte) between palette[n-1] and palette[n], thus saving **6** to **2** bytes.

	This could be used to create shading, or gradients.

- Pattern repeating <a name="pattern-repeating"></a>
	
	> Pattern repeating is currently implemented, and can be used using `-c` flag with the encoder

	While storing pixels to sprite file, pattern repeating find how many repeating pixels are placed in a row [n] -> [n+Inf], thus saving a maximum of **65535** bytes (**89** bytes in practice)
	It's implementation is stored [here](#components-repeat)

## Encoding and decoding <a name="encode-decode"></a>
> Decoding isn't interesting, and should be used for debugging

### Encoding <a name="howto-encode"></a>

> Encoding is the process of turning a JPEG or PNG file into a .sprite file
	
- Use the `encode.py` script in `sprites/proto` to encode any JPEG or PNG file

	```
		usage: encode.py [-h] -i INPUT [-o OUTPUT] [-c]

		optional arguments:
		-h, --help            show this help message and exit
		-i INPUT, --input INPUT
								Input sprite file
		-o OUTPUT, --output OUTPUT
								Output image file
		-c, --compressed      Compress sprite
	```


### Decoding <a name="howto-decode"></a>
> Decoding is the process of turning a .sprite file into a PNG file
	
- Use the `decode.py` script in `sprites/proto` to decode any .sprite file

	```
		usage: decode.py [-h] -i INPUT -o OUTPUT

		optional arguments:
		-h, --help            show this help message and exit
		-i INPUT, --input INPUT
								Input sprite file
		-o OUTPUT, --output OUTPUT
								Output image file
	```
