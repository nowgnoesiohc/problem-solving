function solution(genres, plays) {
    // gemini 모범답안
  const genrePlayCount = new Map();
  const genreSongs = new Map();

  genres.forEach((genre, i) => {
    genrePlayCount.set(genre, (genrePlayCount.get(genre) || 0) + plays[i]);

    if (!genreSongs.has(genre)) genreSongs.set(genre, []);
    genreSongs.get(genre).push({ id: i, play: plays[i] });
  });
  const sortedGenres = [...genrePlayCount.entries()]
    .sort((a, b) => b[1] - a[1])
    .map((entry) => entry[0]);

  result = [];

  sortedGenres.forEach((genre) => {
    const songs = genreSongs.get(genre);

    songs.sort((a, b) => {
      if (a.play !== b.play) return b.play - a.play;
      return a.id - b.id;
    });

    result.push(...songs.slice(0, 2).map((song) => song.id));
  });
    return result;
}
