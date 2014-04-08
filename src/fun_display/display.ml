let get_dims img =
  ((Sdlvideo.surface_info img).Sdlvideo.w, (Sdlvideo.surface_info img).Sdlvideo.h)
 
let sdl_init () =
  begin
    Sdl.init [`EVERYTHING];
    Sdlevent.enable_events Sdlevent.all_events_mask;
  end
 
let rec wait_key () =
  let e = Sdlevent.wait_event () in
    match e with
    Sdlevent.KEYDOWN _ -> ()
      | _ -> wait_key ()
 
let show img dst =
  let d = Sdlvideo.display_format img in
    Sdlvideo.blit_surface d dst ();
    Sdlvideo.flip dst
 
let main () =
  begin
    if Array.length (Sys.argv) < 2 then
      failwith "Il manque le nom du fichier!";
    sdl_init ();
    for i = 1 to (Array.length (Sys.argv))-1 do
   	let img =  Sdlloader.load_image Sys.argv.(i) in
    	let (w,h) = get_dims img in
    	let display = Sdlvideo.set_video_mode w h [`DOUBLEBUF] in
      	show img display;
      	wait_key ();
    done;
      exit 0
  end
 
let _ = main ()
