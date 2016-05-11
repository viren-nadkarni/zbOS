void main() {
    char* video_memory = (char*) 0xb8000;       // first cell of video memory
    *video_memory = 'X';
    while(1);
}
