# Waveform Audio Enhancer

With this nifty tool, you can easily alter audio sample levels in your **.wav** file.

## Installation

**Follow these commands**

1. Cloning remote repositery

```shell
$ git clone https://github.com/michalspano/Waveform-Audio-Enhancer.git 
```

__Alt__: [ZIP Download][DOWNLOAD]

2. Accessing remote repositery

```shell
$ cd Waveform-Audio-Enhancer 
```

3. Running the core enhancement module `*`

```shell
$ ./core $INPUT_PATH $OUTPUT_PATH $ENHANCE_FACTOR 
```

### Custom Makefile (optional)

Custom program target of type `Makefile`.

```bash
$ make sound in=$INPUT_PATH out=$OUTPUT_PATH f=$ENHANCE_FACTOR
```
___

`$INPUT_PATH` - specify the *path* of your input .wav file (i.e., the path of your local file)

`$OUTPUT_PATH` - specify the *path* of your output .wav file (i.e., the path of the output file inserted onto your local disk)

`$ENHANCE_FACTOR` - specify the *numerical value* of sample enhancement (i.e., raise/lower the volume by the specified factor)

`*` This command works similarly as `git mv ...`

___

#### Read more [here][LINK]!

<!-- LINKS AND REFS -->
[LINK]: https://docs.fileformat.com/audio/wav/
[DOWNLOAD]: https://github.com/michalspano/Waveform-Audio-Enhancer/archive/refs/heads/main.zip
