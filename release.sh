dir_name="mechuon1"

if [ -d "$dir_name" ]; then
    rm -r "${dir_name:?}"/*
else
    mkdir "$dir_name"
fi

cp -r src "$dir_name";
cp zadani.txt "$dir_name";
cp Makefile "$dir_name";
cp Doxyfile "$dir_name";
cp prohlaseni.txt "$dir_name";
cp -r examples "$dir_name";
cp cmake-build-debug/game_save.save "$dir_name"/examples;