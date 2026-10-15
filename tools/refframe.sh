#!/bin/sh
# usage: tools/refframe.sh <seconds> out.png   -> 640x400 reference frame from the DOSBox capture (20fps, emulated clock; absolute time is approximate)
ffmpeg -loglevel error -y -ss $1 -i /tmp/claude-1000/-home-gautier-SynologyDrive-code-current-demos-zilog/30d78e4d-6a5d-45da-a815-458c6cbb7835/scratchpad/emu/ref.mkv -frames:v 1 -vf scale=640:400:flags=neighbor $2
