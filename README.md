abort-signal
============

> `SIGABRT` signal handler and raiser for ZZ

## Installation

Add this to your `zz.toml` file:

```toml
[dependencies]
abort_signal = "*"

[repos]
abort_signal = "git+ssh://git@github.com/zzmodules/abort-signal.git"
```

## Usage

```c++
using abort_signal
```

## API

### `abort_was_caught = abort_signal::abort(error)`

Raises the abort signal (`SIGABRT`). If a abort signal callback function
was set, then the raised signal will be caught by it. The default behaviour
will be that of the native `abort()` function when the `SIGABRT` handler is
raises. If the `SIGABRT` signal is caught by another function not set by this
module, then it will be caught there. This function will return `true` if the
`SIGABRT` signal was raised and caught successfully. Check the `error`
if the caller of this function gets a `false` return value.

```c++
using abort_signal::{ abort }
using err

fn main() -> int {
  new+4096 mut error = err::make();
  if abort(&error) {
    // failed to raise an abort signal
    error.elog();
  }
}
```

### `abort_signal::set_abort_callback(callback)`

Sets the abort signal (`SIGABRT`) callback handler function.

```c++
using abort_signal::{ abort, set_abort_callback }
using err

fn onabort() {
  // gracefully abort
}

fn main() -> int {
  new+4096 mut error = err::make();

  set_abort_callback(onabort);

  if abort(&error) {
    // failed to raise an abort signal
    error.elog();
  }

  return 0;
}
```

### `abort_signal::remove_abort_callback()`

Removes the abort signal (`SIGABRT`) callback handler function.

```c++
abort_signal::remove_abort_callback();
```

## License

MIT
