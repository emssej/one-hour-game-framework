#include "callbacks.h"

void
Callbacks_add (Callbacks *cbs, Callback cb)
{
  cbs->callbacks = realloc (cbs->callbacks, sizeof (Callback) *
									 (++cbs->callbacks_size));

  if (cbs->callbacks == NULL)
	 {
		FATAL ("Could not reallocate memory for callback.");
	 }

  cbs->callbacks[cbs->callbacks_size - 1] = cb;
}

void
Callbacks_handle (Callbacks *cbs, CallbackArgs *args)
{
  for (size_t i = 0; i < cbs->callbacks_size; ++i)
	 {
		cbs->callbacks[i](args);
	 }
}

