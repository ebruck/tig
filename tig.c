 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
static int read_properties(FILE *pipe, const char *separators, int (*read)(char *, int, char *, int));
	REQ_NEXT,
	REQ_PREVIOUS,
static struct ref **get_refs(char *id);

struct int_map {
	const char *name;
	int namelen;
	int value;
static int
set_from_int_map(struct int_map *map, size_t map_size,
		 int *value, const char *name, int namelen)
{

	int i;

	for (i = 0; i < map_size; i++)
		if (namelen == map[i].namelen &&
		    !strncasecmp(name, map[i].name, namelen)) {
			*value = map[i].value;
			return OK;
		}

	return ERR;
}

static char *
chomp_string(char *name)
{
	int namelen;

	while (isspace(*name))
		name++;

	namelen = strlen(name) - 1;
	while (namelen > 0 && isspace(name[namelen]))
		name[namelen--] = 0;

	return name;
}

"  -b[N], --tab-size[=N]       Set number of spaces for tab expansion\n"
static char opt_encoding[20]	= "";
static bool opt_utf8		= TRUE;
		 * -b[NSPACES], --tab-size[=NSPACES]::
		if (!strncmp(opt, "-b", 2) ||
			if (opt[1] == 'b') {
	if (*opt_encoding && strcasecmp(opt_encoding, "UTF-8"))
		opt_utf8 = FALSE;

/**
 * ENVIRONMENT VARIABLES
 * ---------------------
 * Several options related to the interface with git can be configured
 * via environment options.
 *
 * Repository references
 * ~~~~~~~~~~~~~~~~~~~~~
 * Commits that are referenced by tags and branch heads will be marked
 * by the reference name surrounded by '[' and ']':
 *
 *	2006-03-26 19:42 Petr Baudis         | [cogito-0.17.1] Cogito 0.17.1
 *
 * If you want to filter out certain directories under `.git/refs/`, say
 * `tmp` you can do it by setting the following variable:
 *
 *	$ TIG_LS_REMOTE="git ls-remote . | sed /\/tmp\//d" tig
 *
 * Or set the variable permanently in your environment.
 *
 * TIG_LS_REMOTE::
 *	Set command for retrieving all repository references. The command
 *	should output data in the same format as git-ls-remote(1).
 **/

#define TIG_LS_REMOTE \
	"git ls-remote . 2>/dev/null"

/**
 * [[history-commands]]
 * History commands
 * ~~~~~~~~~~~~~~~~
 * It is possible to alter which commands are used for the different views.
 * If for example you prefer commits in the main view to be sorted by date
 * and only show 500 commits, use:
 *
 *	$ TIG_MAIN_CMD="git log --date-order -n500 --pretty=raw %s" tig
 *
 * Or set the variable permanently in your environment.
 *
 * Notice, how `%s` is used to specify the commit reference. There can
 * be a maximum of 5 `%s` ref specifications.
 *
 * TIG_DIFF_CMD::
 *	The command used for the diff view. By default, git show is used
 *	as a backend.
 *
 * TIG_LOG_CMD::
 *	The command used for the log view. If you prefer to have both
 *	author and committer shown in the log view be sure to pass
 *	`--pretty=fuller` to git log.
 *
 * TIG_MAIN_CMD::
 *	The command used for the main view. Note, you must always specify
 *	the option: `--pretty=raw` since the main view parser expects to
 *	read that format.
 **/

#define TIG_DIFF_CMD \
	"git show --patch-with-stat --find-copies-harder -B -C %s"

#define TIG_LOG_CMD	\
	"git log --cc --stat -n100 %s"

#define TIG_MAIN_CMD \
	"git log --topo-order --stat --pretty=raw %s"

/* ... silently ignore that the following are also exported. */

#define TIG_HELP_CMD \
	"man tig 2>/dev/null"

#define TIG_PAGER_CMD \
	""


/**
 * FILES
 * -----
 * '~/.tig'::
 *	User configuration file. See "<<config-options, Configuration options>>"
 *	section for examples.
 *
 * '.git/config'::
 *	Repository config file. Read on startup with the help of
 *	git-repo-config(1).
 **/
/**
 * [[config-options]]
 * User Configuration file
 * -----------------------
 * You can permanently set an option by putting it in the `~/.tig` file.
 * The file consists of a series of 'commands'.  Each
 * line of the file may contain only one command.
 *
 * The hash mark ('#'), or semi-colon (';') is used as a 'comment' character.
 * All text after the comment character to the end of the line is ignored.
 * You can use comments to annotate your initialization file.
 *
 * Some sample options:
 *
 * ==========================================================================
 *	# Diff colors
 *	color diff-header	yellow	default
 *	color diff-index	blue	default
 *	color diff-chunk	magenta	default
 *	# UI colors
 *	color title-blur	white	blue
 *	color title-focus	white	blue	bold
 * ==========================================================================
 *
 * [[color-options]]
 * Color options
 * ~~~~~~~~~~~~~
 * Color options control highlighting and the user interface styles.
 * If  your terminal supports color, these commands can be used to assign
 * foreground/backgound combinations to certain areas. Optionally, an
 * attribute can be given as the last parameter. The syntax is:
 *
 * [verse]
 * ..........................................................................
 *	*color* 'area' 'fgcolor' 'bgcolor' '[attributes]'
 * ..........................................................................
 *
 * Valid colors include: *white*, *black*, *green*, *magenta*, *blue*, *cyan*,
 * *yellow*, *red*, *default*. Use *default* to refer to the default terminal
 * colors.
 **/

static struct int_map color_map[] = {
#define COLOR_MAP(name) { #name, STRING_SIZE(#name), COLOR_##name }
	COLOR_MAP(DEFAULT),
	COLOR_MAP(BLACK),
	COLOR_MAP(BLUE),
	COLOR_MAP(CYAN),
	COLOR_MAP(GREEN),
	COLOR_MAP(MAGENTA),
	COLOR_MAP(RED),
	COLOR_MAP(WHITE),
	COLOR_MAP(YELLOW),
};

/**
 * Valid attributes include: *normal*, *blink*, *bold*, *dim*, *reverse*, *standout*,
 * and *underline*. Note, not all attributes may be supported by the terminal.
 **/
static struct int_map attr_map[] = {
#define ATTR_MAP(name) { #name, STRING_SIZE(#name), A_##name }
	ATTR_MAP(NORMAL),
	ATTR_MAP(BLINK),
	ATTR_MAP(BOLD),
	ATTR_MAP(DIM),
	ATTR_MAP(REVERSE),
	ATTR_MAP(STANDOUT),
	ATTR_MAP(UNDERLINE),
};

/**
 * Valid area names are described below. Note, all names are case-insensitive,
 * and you may use '-', '_', and '.' interchangeably. So "Diff-Header",
 * "DIFF_HEADER", and "diff.header" are the same.
 *
 * --
 **/
/**
 * Diff markup::
 *
 * Options concerning diff start, chunks and lines added and deleted.
 *
 * *diff-header*, *diff-chunk*, *diff-add*, *diff-del*
 **/ \
LINE(DIFF_HEADER,  "diff --git ",	COLOR_YELLOW,	COLOR_DEFAULT,	0), \
/**
 * Enhanced git diff markup::
 *
 * Extra diff information emitted by the git diff machinery, such as mode
 * changes, rename detection, and similarity.
 *
 * *diff-oldmode*, *diff-newmode*, *diff-copy-from*, *diff-copy-to*,
 * *diff-rename-from*, *diff-rename-to*, *diff-similarity* *diff-dissimilarity*
 * *diff-tree*, *diff-index*
 **/ \
LINE(DIFF_INDEX,	"index ",	  COLOR_BLUE,	COLOR_DEFAULT,	0), \
LINE(DIFF_OLDMODE,	"old file mode ", COLOR_YELLOW,	COLOR_DEFAULT,	0), \
LINE(DIFF_NEWMODE,	"new file mode ", COLOR_YELLOW,	COLOR_DEFAULT,	0), \
LINE(DIFF_COPY_FROM,	"copy from",	  COLOR_YELLOW,	COLOR_DEFAULT,	0), \
LINE(DIFF_COPY_TO,	"copy to",	  COLOR_YELLOW,	COLOR_DEFAULT,	0), \
LINE(DIFF_RENAME_FROM,	"rename from",	  COLOR_YELLOW,	COLOR_DEFAULT,	0), \
LINE(DIFF_RENAME_TO,	"rename to",	  COLOR_YELLOW,	COLOR_DEFAULT,	0), \
LINE(DIFF_SIMILARITY,   "similarity ",	  COLOR_YELLOW,	COLOR_DEFAULT,	0), \
LINE(DIFF_DISSIMILARITY,"dissimilarity ", COLOR_YELLOW,	COLOR_DEFAULT,	0), \
LINE(DIFF_TREE,		"diff-tree ",	  COLOR_BLUE,	COLOR_DEFAULT,	0), \
/**
 * Pretty print commit headers::
 *
 * Commit diffs and the revision logs are usually formatted using pretty
 * printed headers , unless `--pretty=raw` was given. This includes lines,
 * such as merge info, commit ID, and author and comitter date.
 *
 * *pp-author*, *pp-commit*, *pp-merge*, *pp-date*, *pp-adate*, *pp-cdate*
 **/ \
/**
 * Raw commit header::
 *
 * Usually shown when `--pretty=raw` is given, however 'commit' is pretty
 * much omnipresent.
 *
 * *commit*, *parent*, *tree*, *author*, *committer*
 **/ \
/**
 * Commit message::
 *
 * For now only `Signed-off-by lines` are colorized.
 *
 * *signoff*
 **/ \
/**
 * UI colors::
 *
 * Colors for text not matching any of the above: *default*
 *
 * Status window colors: *status*
 *
 * Title window colors: *title-blur*, *title-focus*
 *
 * Cursor line colors: *cursor*
 *
 * Main view specific: *main-date*, *main-author*, *main-commit*, *main-delim*,
 * *main-tag*, *main-ref*
 **/ \
LINE(MAIN_REF,     "",			COLOR_CYAN,	COLOR_DEFAULT,	A_BOLD), \
/**
 * --
 **/


/*
 * Line-oriented content detection.
 */
	const char *name;	/* Option name. */
	int namelen;		/* Size of option name. */
	{ #type, STRING_SIZE(#type), (line), STRING_SIZE(line), (fg), (bg), (attr) }
static struct line_info *
get_line_info(char *name, int namelen)
{
	enum line_type type;
	int i;

	/* Diff-Header -> DIFF_HEADER */
	for (i = 0; i < namelen; i++) {
		if (name[i] == '-')
			name[i] = '_';
		else if (name[i] == '.')
			name[i] = '_';
	}

	for (type = 0; type < ARRAY_SIZE(line_info); type++)
		if (namelen == line_info[type].namelen &&
		    !strncasecmp(line_info[type].name, name, namelen))
			return &line_info[type];

	return NULL;
}

struct line {
	enum line_type type;
	void *data;		/* User data */
};
#define set_color(color, name, namelen) \
	set_from_int_map(color_map, ARRAY_SIZE(color_map), color, name, namelen)
#define set_attribute(attr, name, namelen) \
	set_from_int_map(attr_map, ARRAY_SIZE(attr_map), attr, name, namelen)
static int
read_option(char *opt, int optlen, char *value, int valuelen)
{
	optlen = strcspn(opt, "#;");
	if (optlen == 0)
		/* The whole line is a comment. */
		return OK;

	else if (opt[optlen] != 0)
		/* Part of the option name is a comment, so the value part
		 * should be ignored. */
		valuelen = 0;
	else
		/* Else look for comment endings in the value. */
		valuelen = strcspn(value, "#;");
	opt[optlen] = value[valuelen] = 0;
	/* Reads: "color" object fgcolor bgcolor [attr] */
	if (!strcmp(opt, "color")) {
		struct line_info *info;
		value = chomp_string(value);
		valuelen = strcspn(value, " \t");
		info = get_line_info(value, valuelen);
		if (!info)
			return ERR;
		value = chomp_string(value + valuelen);
		valuelen = strcspn(value, " \t");
		if (set_color(&info->fg, value, valuelen) == ERR)
			return ERR;
		value = chomp_string(value + valuelen);
		valuelen = strcspn(value, " \t");
		if (set_color(&info->bg, value, valuelen) == ERR)
			return ERR;

		value = chomp_string(value + valuelen);
		if (*value &&
		    set_attribute(&info->attr, value, strlen(value)) == ERR)
			return ERR;

		return OK;
	}

	return ERR;
}

static int
load_options(void)
{
	char *home = getenv("HOME");
	char buf[1024];
	FILE *file;

	if (!home ||
	    snprintf(buf, sizeof(buf), "%s/.tig", home) >= sizeof(buf))
		return ERR;

	/* It's ok that the file doesn't exist. */
	file = fopen(buf, "r");
	if (!file)
		return OK;

	return read_properties(file, " \t", read_option);
}
struct view_ops;
#define displayed_views()	(display[1] != NULL ? 2 : 1)
	struct view_ops *ops;	/* View operations */
	struct line *line;	/* Line index */
struct view_ops {
	/* What type of content being displayed. Used in the title bar. */
	const char *type;
	/* Draw one line; @lineno must be < view->height. */
	bool (*draw)(struct view *view, struct line *line, unsigned int lineno);
	/* Read one line; updates view->line. */
	bool (*read)(struct view *view, struct line *prev, char *data);
	/* Depending on view, change display based on current line. */
	bool (*enter)(struct view *view, struct line *line);
};

static bool
draw_view_line(struct view *view, unsigned int lineno)
{
	if (view->offset + lineno >= view->lines)
		return FALSE;

	return view->ops->draw(view, &view->line[view->offset + lineno], lineno);
}

		if (!draw_view_line(view, lineno))
 * For long loading views (taking over 3 seconds) the time since loading
 * started will be appended:
 *
 *	[main] 77d9e40fbcea3238015aea403e06f61542df9a31 - commit 1 of 779 (0%) 5s
	if (view->lines || view->pipe) {
		unsigned int lines = view->lines
				   ? (view->lineno + 1) * 100 / view->lines
				   : 0;

			lines);
	if (view->pipe) {
		time_t secs = time(NULL) - view->start_time;

		/* Three git seconds are a long time ... */
		if (secs > 2)
			wprintw(view->title, " %lds", secs);
	}

	wmove(view->title, 0, view->width - 1);
			view->win = newwin(view->height, 0, offset, 0);
			wresize(view->win, view->height, view->width);
static void
update_display_cursor(void)
{
	struct view *view = display[current_view];

	/* Move the cursor to the right-most column of the cursor line.
	 *
	 * XXX: This could turn out to be a bit expensive, but it ensures that
	 * the cursor does not jump around. */
	if (view->lines) {
		wmove(view->win, view->lineno - view->offset, view->width - 1);
		wrefresh(view->win);
	}
}
do_scroll_view(struct view *view, int lines, bool redraw)
			if (!draw_view_line(view, line))
		draw_view_line(view, 0);
		draw_view_line(view, view->lineno - view->offset);
	if (!redraw)
		return;

	do_scroll_view(view, lines, TRUE);
move_view(struct view *view, enum request request, bool redraw)
		draw_view_line(view,  prev_lineno);
		do_scroll_view(view, steps, redraw);
	draw_view_line(view, view->lineno - view->offset);

	if (!redraw)
		return;
static void
end_update(struct view *view)
{
	if (!view->pipe)
		return;
	set_nonblocking_input(FALSE);
	if (view->pipe == stdin)
		fclose(view->pipe);
	else
		pclose(view->pipe);
	view->pipe = NULL;
}

	if (view->pipe)
		end_update(view);

			if (view->line[i].data)
				free(view->line[i].data);
	struct line *tmp;
		struct line *prev = view->lines
				  ? &view->line[view->lines - 1]
				  : NULL;

		if (!view->ops->read(view, prev, line))
		report("");
	int nviews = displayed_views();
	struct view *base_view = display[0];
	/* Resize the view when switching between split- and full-screen,
	 * or when switching between two different full-screen views. */
	if (nviews != displayed_views() ||
	    (nviews == 1 && base_view != display[0]))
		resize_display();
		do_scroll_view(prev, lines, TRUE);
		if (split && !backgrounded) {
			/* "Blur" the previous view. */
		}
	if (view->pipe && view->lines == 0) {
		report("");
		move_view(view, request, TRUE);
	case REQ_NEXT:
	case REQ_PREVIOUS:
		request = request == REQ_NEXT ? REQ_MOVE_DOWN : REQ_MOVE_UP;

		if (view == VIEW(REQ_VIEW_DIFF) &&
		    view->parent == VIEW(REQ_VIEW_MAIN)) {
			bool redraw = display[1] == view;

			view = view->parent;
			move_view(view, request, redraw);
			if (redraw)
				update_view_title(view);
		} else {
			move_view(view, request, TRUE);
			break;
		}
		return view->ops->enter(view, &view->line[view->lineno]);
		int nviews = displayed_views();
		for (i = 0; i < ARRAY_SIZE(views); i++) {
			view = &views[i];
				report("Stopped loading the %s view", view->name),
		/* XXX: Mark closed views by letting view->parent point to the
		 * view itself. Parents to closed view should never be
		 * followed. */
		if (view->parent &&
		    view->parent->parent != view->parent) {
			view->parent = view;
 * Pager backend
pager_draw(struct view *view, struct line *line, unsigned int lineno)
	char *text = line->data;
	enum line_type type = line->type;
	int textlen = strlen(text);
			string_copy(view->ref, text + 7);
		while (text && col_offset + col < view->width) {
			char *pos = text;
			if (*text == '\t') {
				text++;
				pos = spaces;
				text = strchr(text, '\t');
				cols = line ? text - pos : strlen(pos);
			waddnstr(view->win, pos, MIN(cols, cols_max));
		for (; pos < textlen && col < view->width; pos++, col++)
			if (text[pos] == '\t')
		waddnstr(view->win, text, pos);
pager_read(struct view *view, struct line *prev, char *line)
	    !*line && prev && !*((char *) prev->data))
	view->line[view->lines].data = strdup(line);
	if (!view->line[view->lines].data)
	view->line[view->lines].type = get_line_type(line);

pager_enter(struct view *view, struct line *line)
	if (line->type == LINE_COMMIT &&
	   (view == VIEW(REQ_VIEW_LOG) ||
	    view == VIEW(REQ_VIEW_PAGER))) {
	 * but if we are scrolling a non-current view this won't properly
	 * update the view title. */
/*
 * Main view backend
 */

struct commit {
	char id[41];		/* SHA1 ID. */
	char title[75];		/* The first line of the commit message. */
	char author[75];	/* The author of the commit. */
	struct tm time;		/* Date from the author ident. */
	struct ref **refs;	/* Repository references; tags & branch heads. */
};
main_draw(struct view *view, struct line *line, unsigned int lineno)
	struct commit *commit = line->data;
	int trimmed = 1;
	if (opt_utf8) {
		authorlen = utf8_length(commit->author, AUTHOR_COLS - 2, &col, &trimmed);
	} else {
		authorlen = strlen(commit->author);
		if (authorlen > AUTHOR_COLS - 2) {
			authorlen = AUTHOR_COLS - 2;
			trimmed = 1;
		}
	}
main_read(struct view *view, struct line *prev, char *line)
		view->line[view->lines++].data = commit;
		if (!prev)
			break;

		commit = prev->data;

		if (!prev)
		commit = prev->data;

main_enter(struct view *view, struct line *line)
	enum open_flags flags = display[0] == view ? OPEN_SPLIT : OPEN_DEFAULT;

	open_view(view, REQ_VIEW_DIFF, flags);
	 **/
	{ 'm',		REQ_VIEW_MAIN },
	{ 'd',		REQ_VIEW_DIFF },
	{ 'l',		REQ_VIEW_LOG },
	{ 'p',		REQ_VIEW_PAGER },
	{ 'h',		REQ_VIEW_HELP },

	/**
	 * View manipulation
	 * ~~~~~~~~~~~~~~~~~
	 * Up::
	 *	This key is "context sensitive" and will move the cursor one
	 *	line up. However, uf you opened a diff view from the main view
	 *	(split- or full-screen) it will change the cursor to point to
	 *	the previous commit in the main view and update the diff view
	 *	to display it.
	 * Down::
	 *	Similar to 'Up' but will move down.
	{ KEY_UP,	REQ_PREVIOUS },
	{ KEY_DOWN,	REQ_NEXT },
	 * j::
	 *	Move cursor one line down.
	{ 'k',		REQ_MOVE_UP },
	{ 'j',		REQ_MOVE_DOWN },
						/* CJK ... Yi */
	update_display_cursor();
static int
read_ref(char *id, int idlen, char *name, int namelen)
{
	struct ref *ref;
	bool tag = FALSE;
	bool tag_commit = FALSE;

	/* Commits referenced by tags has "^{}" appended. */
	if (name[namelen - 1] == '}') {
		while (namelen > 0 && name[namelen] != '^')
			namelen--;
		if (namelen > 0)
			tag_commit = TRUE;
		name[namelen] = 0;
	}

	if (!strncmp(name, "refs/tags/", STRING_SIZE("refs/tags/"))) {
		if (!tag_commit)
			return OK;
		name += STRING_SIZE("refs/tags/");
		tag = TRUE;

	} else if (!strncmp(name, "refs/heads/", STRING_SIZE("refs/heads/"))) {
		name += STRING_SIZE("refs/heads/");

	} else if (!strcmp(name, "HEAD")) {
		return OK;
	}

	refs = realloc(refs, sizeof(*refs) * (refs_size + 1));
	if (!refs)
		return ERR;

	ref = &refs[refs_size++];
	ref->name = strdup(name);
	if (!ref->name)
		return ERR;

	ref->tag = tag;
	string_copy(ref->id, id);

	return OK;
}

	return read_properties(popen(cmd, "r"), "\t", read_ref);
}
static int
read_repo_config_option(char *name, int namelen, char *value, int valuelen)
{
	if (!strcmp(name, "i18n.commitencoding")) {
		string_copy(opt_encoding, value);
	}
	return OK;
}
static int
load_repo_config(void)
{
	return read_properties(popen("git repo-config --list", "r"),
			       "=", read_repo_config_option);
}
static int
read_properties(FILE *pipe, const char *separators,
		int (*read_property)(char *, int, char *, int))
{
	char buffer[BUFSIZ];
	char *name;
	int state = OK;
	if (!pipe)
		return ERR;
	while (state == OK && (name = fgets(buffer, sizeof(buffer), pipe))) {
		char *value;
		size_t namelen;
		size_t valuelen;
		name = chomp_string(name);
		namelen = strcspn(name, separators);
		if (name[namelen]) {
			name[namelen] = 0;
			value = chomp_string(name + namelen + 1);
			valuelen = strlen(value);
		} else {
			value = "";
			valuelen = 0;
		}
		if (namelen)
			state = read_property(name, namelen, value, valuelen);
	if (state != ERR && ferror(pipe))
		state = ERR;
	return state;

	if (load_options() == ERR)
		die("Failed to load user config.");

	/* Load the repo config file so options can be overwritten from
	 * the command line.  */
	if (load_repo_config() == ERR)
		die("Failed to load repo config.");

				report("Prompt interrupted by loading view, "
				       "press 'z' to stop loading views");
				request = REQ_SCREEN_UPDATE;
 * variables described in the  <<history-commands, "History commands">>
 * section.
 * - The cursor can wrap-around on the last line and cause the
 *   window to scroll.
 *
 * - The prompt doesn't work while loading.
 *
 * Copyright (c) 2006 Jonas Fonseca <fonseca@diku.dk>
 * - link:http://www.kernel.org/pub/software/scm/git/docs/[git(7)],
 * - link:http://www.kernel.org/pub/software/scm/cogito/docs/[cogito(7)]
 *
 * Other git repository browsers:
 *
 *  - gitk(1)
 *  - qgit(1)
 *  - gitview(1)