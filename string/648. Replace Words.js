/**
 * @param {string[]} dictionary
 * @param {string} sentence
 * @return {string}
 */

function f(word, dict, maxWordLength) {
    let str = "";
    for(let i=0; i<word.length; i++) {
        str += word[i];
        if(str.length > maxWordLength) { // small opti
            break;
        }
        if(dict.includes(str)) {
            return str;
        }
    }
    return word;
}

var replaceWords = function(dictionary, sentence) {
    let maxWordLength = -1e9;
    for(let it of dictionary) {
        maxWordLength = Math.max(maxWordLength, it.length);
    }

    let arr = sentence.split(" ");
    // console.log(arr.join(" "));
    for(let i=0; i<arr.length; i++) {
        arr[i] = f(arr[i], dictionary, maxWordLength);
    }
    // console.log(arr.join(" "));
    let str = arr.join(" ");
    return str;
};