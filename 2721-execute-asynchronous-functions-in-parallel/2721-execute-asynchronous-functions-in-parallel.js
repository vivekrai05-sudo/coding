/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const results = new Array(functions.length);
        let count = 0;

        if (functions.length === 0) {
            return resolve([]);
        }

        functions.forEach((fn, i) => {
            try {
                fn().then(
                    (res) => {
                        results[i] = res;
                        count++;

                        if (count === functions.length) {
                            resolve(results);
                        }
                    },
                    (err) => {
                        reject(err);
                    }
                );
            } catch (err) {
                reject(err);
            }
        });
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */