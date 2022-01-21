# Sprite engine

# Index

1. [Palette](#main-palette)
	1) [Examples](#palette-examples)
	2) [Sprite Data](#sprite-data)
2. [Compression](#compression)
	1) [Difference Storing](#difference-storing)
	2) [Pattern repeating](#pattern-repeating)

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
	
	> Pattern repeating is currently in debugging state

	While storing pixels to sprite file, pattern repeating find how many repeating pixels are placed in a row [n] -> [n+Inf], thus saving a maximum
	of **65535** bytes
	It's implementation is stored [here](#components-repeat)