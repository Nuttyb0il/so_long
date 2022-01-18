# Sprite engine

# Index

1. [Palette](#main-palette)
	1) [Examples](#palette-examples)
	2) [Sprite Metadata](#sprite-metadata)
	3) [Sprite Data](#sprite-data)
2. [Compression](#compression)

## Palette <a name="main-palette"></a>

> Sprite palette is a small index containing a maximum of 255 colors
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

## Sprite metadata <a name="sprite-metadata"></a>

> Sprite metadata is a chunk of data that's placed just before sprite data

### Components
1) Data length (ranging from **0x00** to **0xFF**)

## Sprite data <a name="sprite-data"></a>

> Sprite data is a way of storing graphics and their corresponding colors in few bytes

### Components

1) Pixel color (**0x00** to **0xFE** pixels) (correspond to a palette **index**)
2) Blink delay (**0x00** to **0xFF**) represents a delay (in frames) where the pixel's color will be swapped to another (if the color is exactly the same, the pixel will not be drawn)
3) EOGL (end of graphic line) -- a **0x00** byte that signal the end of a sprite line (*last byte of data length*)

## Compression

### A list of potential algorithms that could be implemented

- Difference storing

	> Difference storing is currently only a concept

	While creating a palette, DS algorithm can store a decimal difference (1 byte) between palette[n-1] and palette[n], thus saving **6** to **2** bytes.

	This could be used to create shading, or gradients.
